http_proxy = nil

Vagrant.configure("2") do |config|
  config.vm.box = "centos/7"
  config.vm.synced_folder ".", "/vagrant", type: "virtualbox"

  config.vm.provider "virtualbox" do |vb|
    vb.cpus = "11"
    vb.memory = "1024"
  end

  config.vm.provision "ansible" do |ansible|
    ansible.playbook = "ansible/playbook.yml"
  end

  config.vagrant.plugins = [
    "vagrant-vbguest"
    *(http_proxy ? ["vagrant-proxyconf"] : [])
  ]

  config.vbguest.installer_options = { allow_kernel_upgrade: true }

  if Vagrant.has_plugin?("vagrant-proxyconf")
    config.proxy.http     = http_proxy
    config.proxy.https    = http_proxy
    config.proxy.no_proxy = "localhost,127.0.0.1"

    config.proxy.enabled = {
      apt: false,
      chef: false,
      docker: false,
      env: false,
      git: false,
      npm: false,
      pear: false,
      svn: false,
      yum: true,
    }
  end
end
