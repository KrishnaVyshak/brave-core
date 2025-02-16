// Copyright (c) 2022 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import * as React from 'react'
import { useLib } from './useLib'

export const usePasswordStrength = () => {
  // custom hooks
  const { isStrongPassword: checkIsStrongPassword } = useLib()

  // state
  const [password, setPassword] = React.useState<string>('')
  const [confirmedPassword, setConfirmedPassword] = React.useState<string>('')
  const [isStrongPassword, setIsStrongPassword] = React.useState<boolean>(false)

  const onPasswordChanged = React.useCallback(async (value: string) => {
    setPassword(value)
    const isStrong = await checkIsStrongPassword(value)
    setIsStrongPassword(isStrong)
  }, [])

  const hasPasswordError = React.useMemo(() => {
    if (password === '') {
      return false
    }
    return !isStrongPassword
  }, [password, isStrongPassword])

  const hasConfirmedPasswordError = React.useMemo(() => {
    if (confirmedPassword === '') {
      return false
    } else {
      return confirmedPassword !== password
    }
  }, [confirmedPassword, password])

  const isValid = !(
    hasConfirmedPasswordError ||
    hasPasswordError ||
    password === '' ||
    confirmedPassword === ''
  )

  return {
    confirmedPassword,
    password,
    onPasswordChanged,
    setConfirmedPassword,
    isStrongPassword,
    isValid,
    hasConfirmedPasswordError,
    hasPasswordError,
    checkIsStrongPassword
  }
}
