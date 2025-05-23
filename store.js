// Author: Ruben Rehal

import { configureStore } from '@reduxjs/toolkit';
import calorieReducer from './calorieSlice';

export default configureStore({
  reducer: {
    calorie: calorieReducer,
  },
});
