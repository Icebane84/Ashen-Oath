// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "Soul/AshenCognitiveFirewallValidator.h"

/**
 * FAshenAsyncVoiceCompilationWorker
 * 
 * Non-abandonable async task worker parsing and auditing raw compiler output
 * completely off the game thread.
 */
class FAshenAsyncVoiceCompilationWorker : public FNonAbandonableTask
{
public:
	FAshenAsyncVoiceCompilationWorker(
		const FAshenInnerVoicePayload& InRawPayload,
		const TArray<FString>& InAuthorizedImprints,
		UAshenCognitiveFirewallValidator* InValidator)
		: RawPayload(InRawPayload)
		, AuthorizedImprints(InAuthorizedImprints)
		, Validator(InValidator)
	{
	}

	void DoWork()
	{
		if (Validator)
		{
			Result = Validator->ValidatePayload(RawPayload, AuthorizedImprints, SanitizedPayload);
		}
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FAshenAsyncVoiceCompilationWorker, STATGROUP_ThreadPoolAsyncTasks);
	}

	FAshenInnerVoicePayload GetSanitizedPayload() const { return SanitizedPayload; }
	EFirewallValidationResult GetResult() const { return Result; }

private:
	FAshenInnerVoicePayload RawPayload;
	TArray<FString> AuthorizedImprints;
	UAshenCognitiveFirewallValidator* Validator;

	FAshenInnerVoicePayload SanitizedPayload;
	EFirewallValidationResult Result = EFirewallValidationResult::Success;
};
