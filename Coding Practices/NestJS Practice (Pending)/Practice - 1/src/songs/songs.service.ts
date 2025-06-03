import { Injectable } from '@nestjs/common';

interface Song {
  id: string;
  title: string;
}

@Injectable()
export class SongsService {
  private songs: Song[] = [];

  create(id: string, title: string): Song {
    const newSong = { id, title };
    this.songs.push(newSong);
    return newSong;
  }

  findAll(): Song[] | { msg: string } {
    return this.songs.length > 0
      ? this.songs
      : { msg: 'There is not any song.' };
  }

  findOne(SongId: string): Song | { msg: string } {
    const resultSong = this.songs.find((song) => song.id === SongId);
    return resultSong ?? { msg: 'song not found' };
  }

  updateOne(SongId: string, newtitle: string): Song | { msg: string } {
    const updateSong = this.songs.find((song) => song.id === SongId);
    if (updateSong) {
      updateSong.title = newtitle;
      return updateSong;
    }
    return { msg: 'song not found.' };
  }

  deleteOne(SongId: string): { msg: string } {
    const initialLength = this.songs.length;
    this.songs = this.songs.filter((song) => song.id !== SongId);
    if (this.songs.length < initialLength) {
      return { msg: 'Song deleted successfully.' };
    } else {
      return { msg: 'Song not found.' };
    }
  }
}
