// Copyright (c) 2022 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import * as React from 'react'

import {
  StyledCustomBackgroundOption,
  StyledCustomBackgroundOptionSolidColor
} from '../../../components/default'

interface Props {
  color: string
  useSolidColorBackground: (color: string) => void
}

class SolidColorBackgroundOption extends React.PureComponent<Props, {}> {
  onClickColor = () => {
    this.props.useSolidColorBackground(this.props.color)
  }

  render () {
    return (<StyledCustomBackgroundOption onClick={this.onClickColor}>
              <StyledCustomBackgroundOptionSolidColor style={{ backgroundColor: this.props.color }} />
            </StyledCustomBackgroundOption>)
  }
}

export default SolidColorBackgroundOption
