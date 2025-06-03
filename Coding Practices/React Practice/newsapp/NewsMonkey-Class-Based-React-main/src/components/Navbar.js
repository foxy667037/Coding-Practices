import React, { Component } from 'react';
import { Link } from "react-router-dom";

export default class Navbar extends Component {


  render() {
    return (
    <>
        <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
            <div className="container-fluid">
                <Link className="navbar-brand" to="/">NewsMonkey</Link>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/">Home</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/sport">Sports</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/weather">Weather</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/lifestyle">Lifestyle</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/health">Health</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/society">Society</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/business">Business</Link></li>
                        <li class="nav-item"><Link class="nav-link active" aria-current="page" to="/technology">Technology</Link></li>
                    </ul>
                </div>
            </div>
        </nav>
    </>
    )
  }
}
