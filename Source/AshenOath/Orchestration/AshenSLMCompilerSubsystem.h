// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "AshenSLMCompilerSubsystem.generated.h"

/** Broadcast delegate when identity compilation finishes cleanly */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAshenIdentityCompilationCompletedSignature, bool, bSuccess, const FSoulStateVector&, NewSoulState);

/**
 * UAshenSLMCompilerSubsystem
 *
 * GameInstance Subsystem managing async identity compilation, SLM payload requests,
 * and zero-hallucination C++ firewall sanitization.
 */
UCLASS()
class ASHENOATH_API UAshenSLMCompilerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Telemetry")
	FOnAshenIdentityCompilationCompletedSignature OnCompilationCompleted;

	/** Triggers async compilation bridge with telemetry JSON payload and pending memory IDs */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Telemetry")
	void RequestIdentityCompilation(const FString& PayloadJSON, const TArray<FString>& ValidMemoryIDs);

	/** Returns current immutable soul state vector */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SoulState")
	FSoulStateVector GetCurrentSoulState() const { return CurrentSoulState; }

	/** Updates current soul state vector manually if required */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SoulState")
	void SetCurrentSoulState(const FSoulStateVector& NewState) { CurrentSoulState = NewState; }

private:
	/** C++ Zero-Hallucination Firewall Parser */
	bool ExecuteFirewallParser(const FString& JsonPayload, const TArray<FString>& ValidMemoryIDs);

	void OnMockSLMTimerExpired();

	UPROPERTY()
	FSoulStateVector CurrentSoulState;

	TArray<FString> CachedValidIDs;
	FTimerHandle MockApiTimerHandle;
};
