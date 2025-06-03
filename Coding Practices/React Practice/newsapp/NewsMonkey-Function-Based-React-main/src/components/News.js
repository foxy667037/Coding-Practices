import React, { useEffect, useState } from 'react';
import NewsItems from './NewsItems';
import Loader from './Loader';
import PropTypes from 'prop-types';
import InfiniteScroll from 'react-infinite-scroll-component';

const News = (props) => {

  const [articles, setarticles] = useState([]);
  const [loading, setloading] = useState(true);
  const [page, setpage] = useState(1);
  const [totalResults, settotalResults] = useState(0);
  
  const captalizeFirstletter = (string) =>{
    return string.charAt(0).toUpperCase() + string.slice(1);
  }

  const updateNews = async() => {
    props.setProgress(10);
    const url = `https://newsapi.org/v2/top-headlines?country=${props.country}&category=${props.category}&apiKey=${props.apikey}&page=${page}&pageSize=${props.pageSize}`;
    setloading(true);
    let data = await fetch(url);
    props.setProgress(30);
    let parseData = await data.json();
    props.setProgress(70);
    console.log(parseData);
    setarticles(parseData.articles); 
    settotalResults(parseData.totalResults);
    setloading(false);
    props.setProgress(100);
  }
  
  useEffect( () => {
     document.title = `${captalizeFirstletter(props.category)} || MonkeyNews`;
     updateNews();
     // eslint-disable-next-line
  },[])

  const fetchMoredata = async() => {
    const url = `https://newsapi.org/v2/top-headlines?country=${props.country}&category=${props.category}&apiKey=${props.apikey}&page=${page+1}&pageSize=${props.pageSize}`;
    setpage(page + 1);
    let data = await fetch(url);
    let parseData = await data.json();
    console.log(parseData);
    setarticles(articles.concat(parseData.articles)); 
    settotalResults(parseData.totalResults)
    setloading(false);
  }

  // const nextHandleclick = async() => {
  //   this.setState({page: this.state.page + 1});
  //   this.updateNews();
  // }
  
  // const previousHandleclick = async() => {
  //   this.setState({page: this.state.page - 1});
  //   this.updateNews();
  // }

  return (
      <>
        <h2 className='text-center my-3' style={{marginTop:'90px'}}>NewsMonkey - Top Headlines on {captalizeFirstletter(props.category)} Category</h2>
        {loading && <Loader/>}
        <InfiniteScroll
          dataLength={articles.length} //This is important field to render the next data
          next={fetchMoredata}
          hasMore={articles.length !== totalResults}
          loader={<Loader/>}
        >
        <div className='container my-3'>
        <div className="row">
        {articles.map((element)=>{
            return  <div className="col md 4" key={element.url}>
                      <NewsItems title={element.title ? element.title.slice(0, 38) : ""} description={element.description ? element.description.slice(0, 95) : ""} newsurl={element.url} imageUrl={element.urlToImage} author={element.author ? element.author :"Unknown"} date={element.publishedAt ? element.publishedAt : "Unknown"} source={element.source.name ? element.source.name : "Unknown"}/>
                    </div>
        })}
        </div>
        </div>
        </InfiniteScroll>

        {/* <div className='container my-3  d-flex justify-content-between'>
        <button disabled={page + 1 > Math.ceil(totalResults/props.pageSize)} type="button" onClick={nextHandleclick} className="btn btn-dark">Next &rarr;</button>
        <button disabled={page<=1} type="button" onClick={previousHandleclick} className="btn btn-dark"> &larr; Previous</button>
        </div> */}
      </>      
  )
}

const defaultProps = {
  country:'in',
  pageSize:'20',
  category:'general',
}

const propTypes = {
  country: PropTypes.string,
  pageSize: PropTypes.number,
  category: PropTypes.string,
}

export default News;