import React, { Component } from 'react'
import NewsItems from './NewsItems';
import Loader from './Loader';
import PropTypes from 'prop-types';
import InfiniteScroll from 'react-infinite-scroll-component';

export default class News extends Component {

  static defaultProps = {
    country:'in',
    pageSize:'20',
    category:'general',
  }

  static propTypes = {
    country: PropTypes.string,
    pageSize: PropTypes.number,
    category: PropTypes.string,
  }

  constructor(props){
    super(props);
    this.state = {
        articles: [],
        loading: true,
        page:1,
        totalResults:0,
    }
    document.title = `${this.captalizeFirstletter(this.props.category)} || MonkeyNews`;
  }

  captalizeFirstletter = (string) =>{
    return string.charAt(0).toUpperCase() + string.slice(1);
  }

  async updateNews(){
    this.props.setProgress(10);
    const url = `https://newsapi.org/v2/top-headlines?country=${this.props.country}&category=${this.props.category}&apiKey=${this.props.apikey}&page=${this.state.page}&pageSize=${this.props.pageSize}`;
    this.setState({loading: true});
    let data = await fetch(url);
    this.props.setProgress(30);
    let parseData = await data.json();
    this.props.setProgress(70);
    console.log(parseData);
    this.setState({
          articles: parseData.articles, 
          totalResults:parseData.totalResults,
          loading: false,
        })
    this.props.setProgress(100);
  }

  async componentDidMount(){
    this.updateNews();
  }

  fetchMoredata = async() => {
    this.setState({page: this.state.page + 1});
    const url = `https://newsapi.org/v2/top-headlines?country=${this.props.country}&category=${this.props.category}&apiKey=${this.props.apikey}&page=${this.state.page}&pageSize=${this.props.pageSize}`;
    let data = await fetch(url);
    let parseData = await data.json();
    console.log(parseData);
    this.setState({
          articles: this.state.articles.concat(parseData.articles), 
          totalResults:parseData.totalResults,
          loading: false,
        })
    
  }

  // nextHandleclick = async() => {
  //   this.setState({page: this.state.page + 1});
  //   this.updateNews();
  // }
  
  // previousHandleclick = async() => {
  //   this.setState({page: this.state.page - 1});
  //   this.updateNews();
  // }

  render() {
    return (
      <>
            <h2 className='text-center my-3'>NewsMonkey - Top Headlines on {this.captalizeFirstletter(this.props.category)} Category</h2>
            {this.state.loading && <Loader/>}
            <InfiniteScroll
              dataLength={this.state.articles.length} //This is important field to render the next data
              next={this.fetchMoredata}
              hasMore={this.state.articles.length !== this.state.totalResults}
              loader={<Loader/>}
            >
            <div className='container my-3'>
            <div className="row">
            {this.state.articles.map((element)=>{
                return  <div className="col md 4" key={element.url}>
                          <NewsItems title={element.title ? element.title.slice(0, 38) : ""} description={element.description ? element.description.slice(0, 95) : ""} newsurl={element.url} imageUrl={element.urlToImage} author={element.author ? element.author :"Unknown"} date={element.publishedAt ? element.publishedAt : "Unknown"} source={element.source.name ? element.source.name : "Unknown"}/>
                        </div>
            })}
            </div>
            </div>
            </InfiniteScroll>

            {/* <div className='container my-3  d-flex justify-content-between'>
            <button disabled={this.state.page + 1 > Math.ceil(this.state.totalResults/this.props.pageSize)} type="button" onClick={this.nextHandleclick} className="btn btn-dark">Next &rarr;</button>
            <button disabled={this.state.page<=1} type="button" onClick={this.previousHandleclick} className="btn btn-dark"> &larr; Previous</button>
            </div> */}
      </>      
    )
  }
}
