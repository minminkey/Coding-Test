#define MAX_N			5

#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4


#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 50011
#define MAX_SECTION 111
#define MAX_TYPES 511

int Num;

typedef struct _Hash
{
	int typeNum;
	int secNum;
	char key[MAX_NAME_LEN];
	char types[MAX_N][MAX_TAG_LEN];
	struct _Hash *prev;
	struct _Hash *next;
}Hash;

Hash tb[MAX_TABLE];
Hash tt[MAX_TABLE];
Hash typeHead[MAX_TYPES];
Hash section[MAX_SECTION];
int cntSection[MAX_SECTION];

void mstrcpy(char dst[], const char src[]) {
	int c = 0;
	while ((dst[c] = src[c]) != '\0') ++c;
}

int mstrcmp(const char str1[], const char str2[]) {
	int c = 0;
	while (str1[c] != '\0' && str1[c] == str2[c]) ++c;
	return str1[c] - str2[c];
}

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

unsigned long hashType(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TYPES;
	}

	return hash % MAX_TYPES;
}

int findType(const char *key) {
	unsigned long h = hashType(key);
	int cnt = MAX_TYPES;

	while (typeHead[h].key[0] != 0 && cnt--)
	{
		if (mstrcmp(typeHead[h].key, key) == 0)
		{
			return h;
		}
		h = (h + 1) % MAX_TYPES;
	}
}

int find(const char *key)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (mstrcmp(tb[h].key, key) == 0)
		{
			return h;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

void init(int M)
{
	for (int i = 0; i < MAX_TYPES; i++) {
		typeHead[i].key[0] = 0;
		typeHead[i].next = NULL;
		typeHead[i].prev = NULL;
	}
	for (int i = 0; i < MAX_TABLE; i++) {
		tt[i].next = NULL;
		tt[i].prev = NULL;
		tt[i].key[0] = 0;
		tt[i].secNum = 0;
		tb[i].next = NULL;
		tb[i].prev = NULL;
		tb[i].key[0] = 0;
		for (int j = 0; j < MAX_N; j++) {
			tb[i].types[j][0] = 0;
		}
		tb[i].typeNum = 0;
		tb[i].secNum = 0;
	}
	for (int i = 1; i <= M; i++) {
		section[i].next = NULL;
		section[i].prev = NULL;
		cntSection[i] = 0;
	}

}

void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	unsigned long h = hash(mName);
	while (tb[h].key[0] != 0)
	{
		if (mstrcmp(tb[h].key, mName) == 0)
		{
			//printf("\n\n\n%s, %s\n\n\n", tb[h].key, mName);
			return;
		}

		h = (h + 1) % MAX_TABLE;
	}
	mstrcpy(tb[h].key, mName);
	tb[h].typeNum = mTypeNum;
	tb[h].secNum = mSection;
	for (int i = 0; i < mTypeNum; i++) {
		unsigned long typeH = hashType(mTypes[i]);
		while (typeHead[typeH].key[0] != 0)
		{
			if (mstrcmp(typeHead[typeH].key, mTypes[i]) == 0)
			{
				break;
			}
			typeH = (typeH + 1) % MAX_TABLE;
		}
		printf("%s %d\n", mTypes[i], typeH);
		mstrcpy(tt[h].key, mName);
		tt[h].secNum = mSection;
		if (typeHead[typeH].next != NULL)
			typeHead[typeH].next->prev = &tt[h];
		tt[h].next = typeHead[typeH].next;
		tt[h].prev = &typeHead[typeH];
		typeHead[typeH].next = &tt[h];
		mstrcpy(tb[h].types[i], mTypes[i]);
	}
	if (section[mSection].next != NULL)	section[mSection].next->prev = &tb[h];
	cntSection[mSection]++;
	tb[h].next = section[mSection].next;
	tb[h].prev = &section[mSection];
	section[mSection].next = &tb[h];
	//printf("add clear\n");
	//printf("%d %s %d %s %d %d %d\n", h, tb[h].key, tb[h].typeNum, tb[h].types[0], tb[h].secNum, tb[h].prev, tb[h].next);
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	unsigned long idx = hashType(mType);
	while (typeHead[idx].key[0] != 0)
	{
		if (mstrcmp(typeHead[idx].key, mType) == 0)
		{
			break;
		}
		idx = (idx + 1) % MAX_TABLE;
	}
	//int idx = findType(mType);
	Hash* now = typeHead[idx].next;
	int cnt = 0;
	printf("start %d\n",idx);
	while (now != NULL) {
		Hash *next = now->next;
		printf("%s\n", now->key);
		if (now->secNum == mFrom) {
			now->secNum = mTo;
			cnt++;
		}
		now = next;
	}
	printf("%d\n", cnt);
	/*Hash* now = section[mFrom].next;
	int cnt = 0;
	while (now != NULL) {
		//printf("%s\n", now->key);
		Hash *next = now->next;
		int flag = 0;
		for (int i = 0; i < now->typeNum; i++) {
			//printf("%s ", now->types[i]);
			if (mstrcmp(now->types[i], mType) == 0) {
				flag = 1;
				break;
			}
		}
		//printf("\n");
		if (flag) {
			if (now->next != NULL)
				now->next->prev = now->prev;
			now->prev->next = now->next;
			if (section[mTo].next != NULL)
				section[mTo].next->prev = now;
			now->next = section[mTo].next;
			now->prev = &section[mTo];
			section[mTo].next = now;
			cntSection[mFrom]--;
			cntSection[mTo]++;
			cnt++;
		}
		now = next;
	}
	*/
	//printf("%d\n", cnt);
	return cnt;
}

void moveName(char mName[MAX_NAME_LEN], int mSection)
{
	int idx = find(mName);
	tt[idx].secNum = mSection;
	/*
	int idx = find(mName);
	if (tb[idx].next != NULL)
		tb[idx].next->prev = tb[idx].prev;
	tb[idx].prev->next = tb[idx].next;
	if (section[mSection].next != NULL)
		section[mSection].next->prev = &tb[idx];
	tb[idx].next = section[mSection].next;
	tb[idx].prev = &section[mSection];
	section[mSection].next = &tb[idx];
	cntSection[mSection]++;
	cntSection[tb[idx].secNum]--;
	*/
}

void deleteName(char mName[MAX_NAME_LEN])
{
	int idx = find(mName);
	if (tt[idx].next != NULL)
		tt[idx].next->prev = tt[idx].prev;
	tt[idx].prev->next = tt[idx].next;
	tt[idx].next = NULL;
	tt[idx].prev = NULL;

	/*
	int idx = find(mName);
	if (tb[idx].next != NULL)
		tb[idx].next->prev = tb[idx].prev;
	tb[idx].prev->next = tb[idx].next;
	tb[idx].next = NULL;
	tb[idx].prev = NULL;
	cntSection[tb[idx].secNum]--;
	*/
}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	int cnt = 0;
	for (int i = 0; i < mTypeNum; i++) {
		unsigned long idx = hashType(mTypes[i]);
		while (typeHead[idx].key[0] != 0)
		{
			if (mstrcmp(typeHead[idx].key, mTypes[i]) == 0)
			{
				break;
			}
			idx = (idx + 1) % MAX_TABLE;
		}
		//int idx = findType(mTypes[i]);
		Hash *now = typeHead[idx].next;
		while (now != NULL) {
			Hash *next = now->next;
			if (now->secNum == mSection)	cnt++;
			now = next;
		}
	}
	/*
	Hash* now = section[mSection].next;
	while (now != NULL) {
		Hash *next = now->next;
		//printf("name : %s\n", now->key);
		int flag = 0;
		//for (int i = 0; i < now->typeNum; i++) {
		//	printf("%s ", now->types[i]);
		//}
		//printf("\n");
		for (int i = 0; i < mTypeNum; i++) {
			for (int j = 0; j < now->typeNum; j++) {
				if (mstrcmp(mTypes[i], now->types[j]) == 0) {
					flag = 1;
					cnt++;
					break;
				}
			}
			if (flag)	break;
		}
		now = next;
	}
	*/
	//printf("%d\n", cnt);
	return cnt;
}