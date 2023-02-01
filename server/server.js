const express = require('express');

const dotenv=require('dotenv');
dotenv.config({path : './server/config/.env'})                                                      // initialize dotenv

const path = require('path'); 
                                                                                                // gives the current working directory path
const cors = require('cors');



const app = express();



// body parser to access request parameters
app.use(express.json());     // built in middleware





// main page

console.log(path.join(__dirname, 'public'));



// enabling cors for external requests
app.use(cors());   // third party middleware


const connectDB=require('./database/db');
//connecting to database
// turn on db connection by uncommenting

//connectDB();
  

const port=process.env.PORT || 4545;


// custom middleware




// const {myDB}=require('./datbase/fake.container');



// when some one hits the path ie starting file of server this express middle ware finds file with name html only so name starting file as index.html
app.use(express.static(path.join(__dirname, 'public')));  

 // main html file should be named as index.html only

//importing route handlers
const allowAdmin=require('./routes/admin.route');
const { application } = require('express');
const {getAllPlaces,addNewData}=require('./TempDB/DB')



// routes
const search=require('./routes/search');
const { get } = require('http');


app.get('/admin')


app.use('/suggest' ,search)


app.post('/places',(req,res)=>{
  // console.log(req.body);
try{
  let place={
    place : req.body.places,
    latitude : req.body.latitude,
    longitude : req.body.longitude
   }
  
   addNewData(place);


   //console.log(getAllPlaces());
 
    res.send({
      message : 'data recieved to server',
      DB : getAllPlaces()
      

    })

  } catch(err){
    console.log('internal server error' ,err)
  }
   
   
})



  // .use brings all routes [get.post.patch etc]   from route handler we use it as middleware



  app.get('/maproute/:location',(req,res)=>{
    let findLoc=req.params.location;
    // console.log(findLoc);
    let locations=getAllPlaces()
   

   

   res.json(locations.filter((obj) => obj.place.includes(findLoc)))
   
  })






// running server

app.listen(port,()=>{
    console.log((`server running on port ${port}`));
})