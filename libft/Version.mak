#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/28 04:55:56 by greyrol           #+#    #+#              #
#    Updated: 2014/01/19 23:37:31 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# auto increments build number
VERSION_FILE = .version
REV=$(shell date +'%l%M')

VERSION_CHANGES = .changelog
VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_BUILD = $(shell cat $(VERSION_FILE))
VERSION_REV = $(shell echo $(REV) | tr -d ' ')

VERSION_TIME = $(shell date +'%H:%M:%S')
VERSION_DATE = $(shell date +'%Y/%m/%d')

VERSION_FLAGS = -D__VERSION_DATE=$(VERSION_DATE)
VERSION_FLAGS += -D__VERSION_BUILD=$(VERSION_BUILD)
VERSION_FLAGS += -D__VERSION_MAJOR=$(VERSION_MINOR)
VERSION_FLAGS += -D__VERSION_MINOR=$(VERSION_MAJOR)
VERSION_FLAGS += -D__VERSION_REV=$(VERSION_REV)

# build number file
$(VERSION_FILE): $(OBJS) $(OBJS_D)
	@printf "\r\033[KUpdating version ($(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV))\n"
	@if ! test -f $(VERSION_FILE); then echo 0 > $(VERSION_FILE); fi
	@echo $$(($$(cat $(VERSION_FILE)) + 1)) > $(VERSION_FILE)
	@if ! test -f $(VERSION_CHANGES); then touch $(VERSION_CHANGES); fi
	@echo "Version $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV): Library build ($(VERSION_DATE) at $(VERSION_TIME))" | cat - $(VERSION_CHANGES) >> $(VERSION_CHANGES).tmp
	@rm -rf $(VERSION_CHANGES)
	@mv $(VERSION_CHANGES).tmp $(VERSION_CHANGES)
