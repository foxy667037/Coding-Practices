import { Controller, Delete, Put, Get, Post, Param } from '@nestjs/common';
import { SongsService } from './songs.service';

@Controller('songs')
export class SongsController {
  constructor(private songService: SongsService) {}
  @Get()
  findAll(): object[] | { msg: string } {
    return this.songService.findAll();
  }

  @Post('/add')
  createOne(): object {
    return this.songService.create('1234', 'abc');
  }

  @Get('/:id')
  findOne(@Param('id') id: string): object {
    return this.songService.findOne(id);
  }

  @Put('/update/:id')
  updateOne(@Param('id') id: string): object {
    return this.songService.updateOne(id, 'foxy');
  }

  @Delete('/delete/:id')
  deleteOne(@Param('id') id: string): object {
    return this.songService.deleteOne(id);
  }
}
