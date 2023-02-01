const fs = require('fs');



 

const getAllPlaces= ()=>{

    const allPlaces=fs.readFileSync('./server/TempDB/placesDB.json',"utf-8");
    return JSON.parse(allPlaces);
    
} 



// const newo={
//     name: 'Hefgfth center',
//     latitude: 23.33333,
//     longitude : 45.66,
// }



const addNewData= (newobj)=>{
    fs.readFile('./server/TempDB/placesDB.json',"utf-8",(err, data)=>{
    if (err) console.log('error from addNewData func',err.message)
const info= JSON.parse(data)
// console.log(info)
info.push(newobj)
fs.writeFileSync('./server/TempDB/placesDB.json',JSON.stringify(info,null ,1).toLowerCase(),(err)=>{
    if(err){ console.log(err.message)};
    



})
console.log('added sucessfully')

})
}
    
// addNewData(newo)
//console.log(getAllPlaces())module
module.exports={addNewData,getAllPlaces}