/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    
    var ans = []

    const arrayLen = arr.length;
    
    let i = 0;

    while(i < arrayLen){
        let j = 0;
        var chunk = []
        while(i < arrayLen && j < size){
            chunk.push(arr[i]);
            i++;
            j++;
        }
        ans.push(chunk);
    }
    return ans;
};
