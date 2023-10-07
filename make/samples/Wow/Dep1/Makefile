# This include only works when invoked from this dir.
# include ../flags/Makefile

# This include only works when invoked from the root dir with the -f flag.
# include $(CURDIR)/flags/Makefile

# PHONY prevents -f invocations from parent from thinking this is cached. Not
# sure why it thinks it's cached. This isn't an issue when using cd.
.PHONY: dep1
dep1:
	@echo "I'm dep 1"

passMeSome:
	@echo "Pass me some coolyo: "$(COOL)

passMeManual:
	@echo "Pass me manual: "$(manual)

pum:
	@echo "The flags from Dep1: $(flags)"
