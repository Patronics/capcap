sudo apt install -y make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncursesw5-dev xz-utils tk-dev libxml2-dev libxmlsec1-dev libffi-dev liblzma-dev libatlas3-base portaudio19-dev


#install pyenv (used to get python 3.7, as required for coqui stt)
curl https://pyenv.run | bash

#add pyenv to path and enable it
# the sed invocation inserts the lines at the start of the file
# after any initial comment lines
sed -Ei -e '/^([^#]|$)/ {a \
export PYENV_ROOT="$HOME/.pyenv"
a \
export PATH="$PYENV_ROOT/bin:$PATH"
a \
' -e ':a' -e '$!{n;ba};}' ~/.profile
echo 'eval "$(pyenv init --path)"' >>~/.profile

export PYENV_ROOT="$HOME/.pyenv"
export PATH="$PYENV_ROOT/bin:$PATH"

exec $SHELL

pyenv update

pyenv install  3.7.13
pyenv global 3.7.13

#wget https://github.com/coqui-ai/STT/releases/download/v1.3.0/stt-1.3.0-cp37-cp37m-linux_aarch64.whl
#pip install stt-1.3.0-cp37-cp37m-linux_aarch64.whl
#adjust above as needed for architecture, above is 64 bit, 32 bit may be needed instead
wget https://github.com/coqui-ai/STT/releases/download/v1.3.0/stt-1.3.0-cp37-cp37m-linux_armv7l.whl
pip install stt-1.3.0-cp37-cp37m-linux_armv7l.whl


pip install -r requirements.txt


mkdir models
cd models


wget https://coqui.gateway.scarf.sh/english/coqui/v1.0.0-large-vocab/model.tflite
wget https://coqui.gateway.scarf.sh/english/coqui/v1.0.0-large-vocab/large_vocabulary.scorer
