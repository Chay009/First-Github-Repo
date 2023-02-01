//@route  /admin



const express = require('express');

const router=express.Router(); 
const Places=require('../models/places.model')
const mongoose = require('mongoose');
          
 // there will be many routes to our main application to handle routes we use this 


//const getplaces=require('../controllers/admin.control')

// here the / is the route  belong to admin our js file eg  all routes to /admin  are handled USING THIS ROUTE  so use / for users not /users while using route


router.post('/', async (req,res)=>{


      }
      )
module.exports=router;  // here we are exporting THIS CURRENT file router which handles admin routes 