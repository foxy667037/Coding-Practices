import React, { Component } from 'react'

export default class NewsItems extends Component {

  render() {
    let {title, description , imageUrl ,newsurl, author, date, source} = this.props;
    return (
      <div className='my-3'> 
        <div className="card" style={{width: "18rem"}}>
            <div style={{display:'flex',justifyContent:'flex-end',position:'absolute',right:'0'}}><span className=" badge rounded-pill bg-danger">{source}</span></div>
            <img src={!imageUrl ? "https://ichef.bbci.co.uk/news/1024/branded_news/B044/production/_133042154_gettyimages-2107854073.jpg" : imageUrl} className="card-img-top" alt="..."/>
            <div className="card-body">
                <h5 className="card-title">{title}...</h5>
                <p className="card-text">{description}...</p>
                <p className="card-text"><small className="text-body-secondary">By {!author ? "Unknown" : author} on {new Date(date).toGMTString()}</small></p>
                <a href={newsurl} rel='noreferrer' target="_blank" className="btn btn-sm btn-primary">Read More</a>
            </div>
        </div>
      </div>
    )
  }
}
