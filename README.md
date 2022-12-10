# xmas_tree

You can see a pretty nice Xmas tree :)

## Requirements

- Ansible
  - https://github.com/ansible/ansible
- Vagrant
  - https://www.vagrantup.com/
- VirtualBox
  - https://www.virtualbox.org/

## How to see the tree?

First, clone this repository at anywhere you want, then change the directory.

```console
$ git clone https://github.com/yskuniv/xmas_tree.git
$ cd xmas_tree/
```

If you are in a proxy environment, you might setup for the proxy.

Edit first line in `Vagrantfile` like the following.

```ruby
# http_proxy = nil
http_proxy = "<your proxy url>"

Vagrant.configure("2") do |config|
  config.vm.box = "centos/7"
  config.vm.synced_folder ".", "/vagrant", type: "virtualbox"
  ...
```

Run `./build_and_start_tree.sh` once, then you're asked to install a vagrant plugin locally (it means in the current directory). Just type 'y' and Enter to continue.

```console
$ ./build_and_start_tree.sh
Vagrant has detected project local plugins configured for this
project which are not installed.

  vagrant-vbguest
Install local plugins (Y/N) [N]:   # type 'y' and Enter here
```

The result is as the following. First time you run `./build_and_start_tree.sh`, it just finished with only installing the plugin.

```console
Install local plugins (Y/N) [N]: y
Installing the 'vagrant-vbguest' plugin. This can take a few minutes...
Fetching micromachine-3.0.0.gem
Fetching vagrant-vbguest-0.30.0.gem
Installed the plugin 'vagrant-vbguest (0.30.0)'!


Vagrant has completed installing local plugins for the current Vagrant
project directory. Please run the requested command again.
$
```

Run `./build_and_start_tree.sh` again, then the building will start. Wait a moment to finish it.

```console
$ ./build_and_start_tree.sh
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Importing base box 'centos/7'...
==> default: Matching MAC address for NAT networking...
==> default: Checking if box 'centos/7' version '2004.01' is up to date...
==> default: Setting the name of the VM: xmas_tree_default_1662556450228_72174
==> default: Clearing any previously set network interfaces...
==> default: Preparing network interfaces based on configuration...
    default: Adapter 1: nat
==> default: Forwarding ports...
    default: 22 (guest) => 2222 (host) (adapter 1)
==> default: Running 'pre-boot' VM customizations...
==> default: Booting VM...
==> default: Waiting for machine to boot. This may take a few minutes...
    default: SSH address: 127.0.0.1:2222
    default: SSH username: vagrant
    default: SSH auth method: private key
...
```

Finally, you can see the nice tree. Enjoy your tree and Merry Xmas!!
