import React from 'react';
import { Navbar, Nav } from 'react-bootstrap';
import { LinkContainer } from 'react-router-dom';
function NavigationBar() {
return (
    <div className="App">
    <ul>
      <li>
        <Link to="/">Home</Link>
      </li>
      
    </ul>
</div>

);
}
export default NavigationBar;