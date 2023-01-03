# Makefile

define add_example
	@echo "" >> README.md
	@echo "## $(1)" >> README.md
	@echo "" >> README.md
	@echo '```stl' >> README.md
	@python $(1).py && cat $(1).stl >> README.md
	@echo '```' >> README.md
endef

build:
	@rm -rf README.md
	@echo "# Examples" >> README.md
	$(call add_example,simple)
	$(call add_example,cylinder)
.PHONY: build
