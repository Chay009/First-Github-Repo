 
  

 
var map_init = L.map('map', {
    center: [23.814296468133172, 86.44118417874446],
   
 
    zoom: 17.5,
    markerZoomAnimation :true,
});




var OSM = L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
}).addTo(map_init);








// admin dont need to acess his location
/*L.Control.geocoder().addTo(map_init);
if (!navigator.geolocation) {
    console.log("Your browser doesn't support geolocation feature!")
} else {
    setInterval(() => {
        navigator.geolocation.getCurrentPosition(getPosition)
    }, 5000);
};
*/







//var marker, circle, lat, long, accuracy;

/*function getPosition(position) {
    // console.log(position)
    lat = position.coords.latitude
    long = position.coords.longitude
    accuracy = position.coords.accuracy

    if (marker) {
        map_init.removeLayer(marker)
    }

    if (circle) {
        map_init.removeLayer(circle)
    }

    marker = L.marker([lat, long])
   
   // circle = L.circle([lat, long], { radius: accuracy })

    /*var featureGroup = L.featureGroup([ marker]).addTo(map_init)
    map_init.flyTo([lat,long],18,{
        animate : true,
        duration : 1,
    })

    //map_init.fitBounds(featureGroup.getBounds())
    

    console.log("Your coordinate is: Lat: " + lat + " Long: " + long + " Accuracy: " + accuracy)
}*/






/*const createAdminMarker=(coordinates)=>{

const markersArr=[];

if(markersArr.length<1)
{
    myMarker=L.marker(coordinates,{
        draggable:false,
    })

var popup=mymarker.bindPopup(popupContent,{
            keepInView: true,
            closeButton: false
});

 map_init.addTo(myMarker)
markers.push(myMarker)
alert(markersArr.length)




}


}

*/


const popupContent=(a,b)=>
{`<div class="container">
<div class="container-close">&times;</div>

<div class="container-text">
  <h2>You are an admin!  <br>Enter the place name to store in DB</h2>
  <div class ="coord-details">
  ${[a,b]} </div>
  <input type="text" placeholder="Enter Location name">
  <br></br>
  <button type="submit">Subscribe</button>
  <span></span>
</div>
</div>`
}


const markersArr=[];
var markergroup=L.layerGroup().addTo(map_init);



    map_init.on('click',(e)=>{
 


   popupContent(e.latlng.lat,e.latlng.lng)

      
 mymarker=L.marker([e.latlng.lat,e.latlng.lng])
 .addTo(markergroup)
 .bindPopup(popupContent,{
     keepInView: true,
     closeButton: false
     })
     .openPopup();
        //console.log(e.latlng.lat,e.latlng.lng)

         // sending coordinates and name from admin
         var p = document.createElement("p");
        p.textContent=coords
         
         
document.querySelector('.coord-details').appendChild(p)



       
     
        
        
        
        
markersArr.push(mymarker)
            

/*for(var i=0;i<markersArr.length-1;i++) {
         console.log(markersArr[i]._leaflet_id
            )*/
           // console.log(markersArr._leaflet_id)


            

            

                 

          
            //map_init.();
           
            


                           // server running on  IP of samsung A51 hotspot  
        axios.post('http://192.168.93.221:6969/coordinates', {

                        latitude : e.latlng.lat,
                        longitude : e.latlng.lng,

                                        }
          )
          .then(function (response) {
            console.log(response);
          })
          .catch(function (error) {
            console.log(error);
          })
    
          

          console.log(markersArr.length)



          if(markersArr.length>1)
          {

            markergroup.removeLayer(markersArr[i])

           
          }
          
         } )



 /*fetch('http://192.168.93.221:6969/coordinates', {
    Method: 'POST',
    Headers: {
      'Accept': 'application.json',
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
        "latitude": e.latlng.lat,
        "longitude": e.latlng.lng,

    })*/


    
  
