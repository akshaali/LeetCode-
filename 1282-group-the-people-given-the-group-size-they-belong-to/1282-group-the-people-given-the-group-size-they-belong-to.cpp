function groupThePeople(groupSizes: number[]): number[][] {
    let obj = {};
    let out = [];
    for(let i=0; i<groupSizes.length; i++){
        if(obj[groupSizes[i]]){
            obj[groupSizes[i]] = [...obj[groupSizes[i]], i];
        }else{
            obj[groupSizes[i]] = [i];
        }
        if(obj[groupSizes[i]].length == groupSizes[i] ){
            out.push(obj[groupSizes[i]]);
            delete obj[groupSizes[i]];
        }
    }
     console.log(obj);
    console.log(out);
     return out;
};