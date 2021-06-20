import { IBaseItem, IItem } from "../interfaces/IItem";
import { dataItems } from "../data/dataItems";

export const findAll = async (): Promise<IItem[]> => Object.values(dataItems);

export const find = async (id: number): Promise<IItem> => dataItems[id];

export const create = async (newItem: IBaseItem): Promise<IItem> => {
  const id = new Date().valueOf();

  dataItems[id] = {
    id,
    ...newItem,
  };

  return dataItems[id];
};

export const update = async (
  id: number,
  itemUpdate: IBaseItem
): Promise<IItem | null> => {
  const item = await find(id);

  if (!item) {
    return null;
  }

  dataItems[id] = { id, ...itemUpdate };

  return dataItems[id];
};

export const remove = async (id: number): Promise<null | void> => {
  const item = await find(id);

  if (!item) {
    return null;
  }

  delete dataItems[id];
};
