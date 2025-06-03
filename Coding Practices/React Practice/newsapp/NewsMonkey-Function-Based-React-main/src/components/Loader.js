import loading from './loader.gif'
import React from 'react'

const Loader = () => {
    return (
      <div  className='text-center'>
        <img className='my-3' src={loading} alt='loading'/>
      </div>
    )
}

export default Loader;