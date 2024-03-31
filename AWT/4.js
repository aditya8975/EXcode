// Import necessary modules
const express = require('express');

// Create an instance of Express app
const app = express();
const port = 3000;

// Sample data
const users = [
  { id: 1, name: 'John' },
  { id: 2, name: 'Jane' },
  { id: 3, name: 'Doe' }
];

// Define routes
app.get('/', (req, res) => {
  res.send('Welcome to my API!');
});

// Route to get all users
app.get('/users', (req, res) => {
  res.json(users);
});

// Route to get a single user by ID
app.get('/users/:id', (req, res) => {
  const id = parseInt(req.params.id);
  const user = users.find(user => user.id === id);
  if (!user) {
    res.status(404).send('User not found');
  } else {
    res.json(user);
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});




//////////////////////////////////////////////////////////////////
const express = require('express');
const axios = require('axios');

const app = express();
const port = 3000;

// Route to fetch data from Mockaroo API
app.get('/mock-data', async (req, res) => {
  try {
    const response = await axios.get('https://api.mockaroo.com/api/your_endpoint.json?key=your_api_key');
    const data = response.data;
    res.json(data);
  } catch (error) {
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});

///////////////////////////////////////////////////////////////
const express = require('express');
const axios = require('axios');

const app = express();
const port = 3000;

// Route to fetch data from Cat Fact Ninja API
app.get('/cat-fact', async (req, res) => {
  try {
    const response = await axios.get('https://catfact.ninja/fact');
    const data = response.data;
    res.json(data);
  } catch (error) {
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});


////////////////////////////////////////////////////////////////////////////////

const express = require('express');
const axios = require('axios');

const app = express();
const port = 3000;

// Route to fetch data from Cat Fact Ninja API using Promise
app.get('/cat-fact', (req, res) => {
  new Promise((resolve, reject) => {
    axios.get('https://catfact.ninja/fact')
      .then(response => {
        resolve(response.data);
      })
      .catch(error => {
        reject(error);
      });
  })
  .then(data => {
    res.json(data);
  })
  .catch(error => {
    res.status(500).json({ error: 'Internal Server Error' });
  });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});

////////////////////////////////////////////////////////////////////////////////////////////////////
const express = require('express');
const app = express();
const port = 3000;

// Sample data (in a real application, this would come from a database)
let products = [
  { id: 1, name: 'T-Shirt', price: 20 },
  { id: 2, name: 'Jeans', price: 40 },
  { id: 3, name: 'Shoes', price: 50 }
];

let cart = [];

// Get all products
app.get('/products', (req, res) => {
  res.json(products);
});

// Get a product by ID
app.get('/products/:id', (req, res) => {
  const id = parseInt(req.params.id);
  const product = products.find(product => product.id === id);
  if (!product) {
    res.status(404).json({ error: 'Product not found' });
  } else {
    res.json(product);
  }
});

// Add a product to the cart
app.post('/cart/add', (req, res) => {
  const productId = parseInt(req.body.productId);
  const product = products.find(product => product.id === productId);
  if (!product) {
    res.status(404).json({ error: 'Product not found' });
  } else {
    cart.push(product);
    res.json({ message: 'Product added to cart', cart });
  }
});

// Get the current cart
app.get('/cart', (req, res) => {
  res.json(cart);
});

// Place an order
app.post('/order', (req, res) => {
  // In a real application, you would process the order (e.g., save to database) and clear the cart
  const order = {
    items: cart,
    total: cart.reduce((acc, cur) => acc + cur.price, 0)
  };
  cart = [];
  res.json({ message: 'Order placed successfully', order });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
