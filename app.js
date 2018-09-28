const express = require('express');
const server = express();

server.get('/', (req, res) => {
  var value = req.query.sensor;
  var value2 = req.query.sensor2;
  console.log(value);
  res.status(200).send(value);
});


server.listen(3000, () => {
  console.log('server started on port 3000');
});
