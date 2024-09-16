# ProtaAI
A Prototype Neural Network!

Uses Synapse objects (pointer to a neuron and a weight value), which establish
a connection between neurons. These can then be removed from the neurons to 
_"prune"_ the connection. This is hopefully meant to mimmick pruning in the 
development of human brains, optimizing the neural networks to run much faster


# BUILDING
Clone the repository
```
git clone https://github.com/MiniFalafel/ProtaAI.git
```

cd into main folder
```
cd ProtaAI/
```

Run the relevant setup script:
## Visual Studio (Windows)
```
setup/setup-vs2022.bat
```
## VS Code (Linux)
```
./setup/setup-vscode.sh
```

## LINUX NOTES
*	vscode script will generate makefiles. for the workspace and projects. You need to run those makefiles from the workspace directory using
	```
	make config=CONFIG
	```
*	Be sure to replace `CONFIG` with either `linuxdebug` or `linuxrelease`. Otherwise, the compiler might define WINDOWS by default, breaking it and causing errors.


