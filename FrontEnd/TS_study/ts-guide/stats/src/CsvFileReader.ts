import { readFileSync } from 'fs';
import { DataReader } from './DataReader';

export class CsvFileReader implements DataReader {

  public data: string[][] = [];

  constructor(public filename: string) { }

  read(): void {
    this.data = readFileSync(this.filename, {
      encoding: 'utf-8'
    })
      .split('\n')
      .map((row: string): string[] => row.split(','));
  }
  
}