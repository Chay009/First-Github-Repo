const mongoose=require('mongoose');
const placeSchema = new mongoose.Schema(
  {
    name: 
    {
      type :String,
      unique :true,
    }
    ,
    latitude:
    {
       type :Number,
       unique :true,
      },
    
    longitude:
    
    {
      type :Number,
      unique :true,
      },
    }
  );


module.exports = mongoose.model('Place', placeSchema);