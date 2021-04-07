function solution(relation) {
    const tuples = relation[0].length,
      rows = relation.length;
    const cKey = [];
  
    for (let i = 1; i <= 1 << tuples; i++) {
      const set = new Set();
  
      for (let j = 0; j < rows; j++) {
        let key = "";
  
        for (let k = 0; k < tuples; k++) {
          if (i & (1 << k)) {
            key += relation[j][k];
          }
        }
        set.add(key);
      }
  
      // 유일성 및 최소성 체크
      if (rows === set.size && isMinimal(cKey, i)) {
        cKey.push(i);
      }
    }
    return cKey.length;
  }
  
  // 최소성 체크
  function isMinimal(cKey, index) {
    for (let i = 0; i < cKey.length; i++) {
      if ((cKey[i] & index) == cKey[i]) return false;
    }
    return true;
  }