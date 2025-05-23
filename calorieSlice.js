// Author: Ruben Rehal

import { createSlice } from '@reduxjs/toolkit';

const calorieSlice = createSlice({
  name: 'calorie',
  initialState: {
    totalCalories: 0,
    foodLog: []
  },
  reducers: {
    addFood: (state, action) => {
      state.foodLog.push(action.payload);
      state.totalCalories += action.payload.calories;
    },
    resetLog: (state) => {
      state.totalCalories = 0;
      state.foodLog = [];
    }
  }
});

export const { addFood, resetLog } = calorieSlice.actions;
export default calorieSlice.reducer;
