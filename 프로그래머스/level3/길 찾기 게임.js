let node = [];
let preAns = [];
let postAns = [];

const makeTree = (p, c) => {
    if(node[p].x>node[c].x){
        if(node[p].left===null){
            node[p].left = c;
        }
        else{
            makeTree(node[p].left, c);
        }
    }
    else{
        if(node[p].right===null){
            node[p].right = c;
        }        
        else{
            makeTree(node[p].right, c);
        }
    }
}

const preorder = (now) => {
    preAns.push(now);
    if(node[now].left!==null)   preorder(node[now].left);
    if(node[now].right!==null)   preorder(node[now].right);
}
const postorder = (now) => {
    if(node[now].left!==null)   postorder(node[now].left);
    if(node[now].right!==null)   postorder(node[now].right);
    postAns.push(now);
}

function solution(nodeinfo) {
    var answer = [];
    for(let i=0; i<=nodeinfo.length; i++){
        let obj = {x:undefined, value: undefined, left:null, right:null};
        node.push(obj);
    }
    for(let i=0; i<nodeinfo.length; i++){
        node[i+1].x = nodeinfo[i][0];
        node[i+1].value = i+1;
        nodeinfo[i].push(i+1);
    }
    nodeinfo.sort((a,b)=>{
        if(a[1]===b[1]) return a[0]-b[0];
        return b[1] - a[1];
    });
    let root = nodeinfo[0][2];
    for(let i=1; i<nodeinfo.length; i++){
        makeTree(root, nodeinfo[i][2]);
    }
    preorder(root);
    postorder(root);
    answer.push(preAns);
    answer.push(postAns);
    return answer;
}K