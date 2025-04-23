//random numbers to generate and compare
var random=4;
let randomInt= Math.floor (Math.random()*10);
if(random==randomInt){
    console.log("true",randomInt);
}
else 
console.log("false",random,randomInt);
//console.log(random==randomInt);
---------------------------------------------

//map method
const numbers=[1,2,3,4,5,6,7,8,9,10];
const res=numbers.map((num)=>{
    return num+20
})
console.log(res);
----------------------------------------------

//vowels
 const names = ['car', 'cat', 'can', 'Den', 'Dog', 'elephant', 'fox'];
const vowels = ['a', 'e', 'i', 'o', 'u'];
const filteredNames = names.filter(name => 
    vowels.some(vowel => name.toLowerCase().includes(vowel))
);
console.log(filteredNames);

