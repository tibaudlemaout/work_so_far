const express = require('express');
const app = express();
const port = 3000; // this should be in the . env file /!

app.get('/' , ( req , res ) => {
    res.send('Hello World !')
})
app.get('/name/:name' , ( req , res ) => {
    const name = req.params.name;
    res.type('text').send(`Hello ${name}!`)
})
app.get('/name/:name' , ( req , res ) => {
    const name = req.params.name;
    res.type('html').send(`Hello ${name}!`)
})
app.get('/name/:name' , ( req , res ) => {
    const name = req.params.name;
    res.type('json').send(`Hello ${name}!`)
})
app.get('/date' , (req , res ) => {
    const date = new Date()
    const year = String(date.getFullYear()).padStart(2, '0')
    const month = String(date.getMonth()).padStart(2, '0')
    const day = String(date.getDate()).padStart(2, '0')
    res.send(`${year}-${month}-${day}`)
})
app.listen(port , () => {
    console . log (`Example app listening on port ${port}`) ;
})
