// Getters & Setters
class Plant {
  private _species: string = 'Default';

  get species() {
    return this._species;
  }

  set species(value: string) {
    if (value.length >= 3) { this._species = value; }
  }
};

const plant = new Plant();
console.log(plant.species);

plant.species = 'AB';
console.log(plant.species);

plant.species = 'ABC';
console.log(plant.species);
