#Vectron
##A UE4 vector field editor 
Vectron is a In Engine Vector Field Editor Plugin for Unreal Engine 4

Vectron Can:

- Import Existing FGA Files
- Manipulate them using Primitive effectors that can Attract, Repulse, or give of a Constant force.
- Export them as FGA Files For use in UE4 particle systems.

This is all done in the UE4 Editor window using a vector field analogue, AVectronBoundingBox and effector primitives.

###Import
To import a .fga file into a AVectronBoundingBox, Move the source file into the actual content folder and wait for the contentbrowser to update. 
*Do not do this using the import button!*
Select it in the content browser and click on Vectron->Import to import it into your scene as a AVectronBoundingBox.
The AVectronBoundingbox a can be moved around the world in the editor.
You can change the intensity of the vector field in it's components

###Manipulation
To change a AVectronBoundingBox select Vectron->Add Effector
This creates a Vectron Primitive Effector which can be moved about the world.
In order to have it affect a Vector Field, it must be assigned a static mesh. you can do this in its components.
Also in it's components, for the primitive to affect a field, you must assign it one of 3 forces, Attractive, Constant, and Repulsive.
- Attractive Attracts Particles towards the mesh.
- Repulsive forces them away from the primitive
- Constant creates a constant force in a specified direction

###Export
To Export your vector field to a FGA File, select your AVectronBoundingBox in the outliner and select Vectron->Export.
The Field will be exported to your current directory in the content browser as vfnew.fga.