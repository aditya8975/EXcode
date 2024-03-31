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
