include flags/Makefile

SHELL=/usr/local/bin/bash
export COOL="oh yeah"

wow:
	@echo "Current shell: $(SHELL)"
	@# First option to execute a sub-makefile.
	@cd Dep1 && $(MAKE)
	@cd Dep1 && $(MAKE) passMeSome
	@cd Dep1 && $(MAKE) passMeManual manual=hand
	@# -f to manually specify a sub-makefile. BEST OPTION!
	@$(MAKE) -f Dep1/Makefile dep1
	@$(MAKE) -f Dep1/Makefile passMeSome
	@$(MAKE) -f Dep1/Makefile passMeManual manual=hand
	@# -C is equivalent to cd approach
	@$(MAKE) -C Dep1 dep1
	@$(MAKE) -C Dep1 passMeSome
	@$(MAKE) -C Dep1 passMeManual manual=hand

pum:
	@echo "The flags from root: $(flags)"
