// Abstract Classes
abstract class Project {
  public projectName: string = 'Default';
  public budget: number = 1000;

  abstract changeName(name: string): void;

  public calculateBudget() {
    return this.budget * 2;
  };
};

class ITProject extends Project {
  public changeName(name: string): void {
    this.projectName = name;
  };
};

const newProject = new ITProject();
console.log(newProject);

newProject.changeName('Super IT Project');
console.log(newProject);
