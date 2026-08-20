// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenCanonicalPromiseSubsystem.generated.h"

class UAshenPromiseLedgerComponent;
class UAshenSemanticContextMatcherComponent;
class UAshenRetroactiveMarginaliaInscriberComponent;

/**
 * UAshenCanonicalPromiseSubsystem
 * 
 * Central world subsystem coordinating canonical promise registration,
 * crisis context reactivation, and unnotified retroactive journal marginalia.
 */
UCLASS()
class ASHENOATH_API UAshenCanonicalPromiseSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCanonicalPromiseSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Swears and registers a new canonical promise */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Promise")
	FCanonicalPromiseRecord SwearCanonicalPromise(
		FName TargetCompanion,
		const FString& PromiseText,
		EPromiseDomainScope Scope,
		FGameplayTag ContextTag);

	/** Evaluates active promises against current crisis conditions */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Promise")
	bool CheckCrisisPromiseReactivation(
		FGameplayTag CurrentCrisisTag,
		FName ActiveCompanion,
		FCanonicalPromiseRecord& OutReactivatedPromise);

	/** Resolves the status of an existing promise */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Promise")
	bool ResolvePromise(const FString& PromiseId, EPromiseResolutionStatus NewStatus);

	/** Inscribes a secret companion marginalia on an old journal page */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Journal")
	FRetroactiveMarginaliaEntry InscribeRetroactiveMarginalia(
		int32 PageIndex,
		FName Author,
		const FString& NoteContent,
		EMarginaliaInkMedium Medium);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Promise")
	FOnPromiseRegistered OnPromiseRegistered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Promise")
	FOnPromiseStatusChanged OnPromiseStatusChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Promise")
	FOnPromiseCrisisReactivated OnPromiseCrisisReactivated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Journal")
	FOnRetroactiveMarginaliaInscribed OnRetroactiveMarginaliaInscribed;

protected:
	UPROPERTY()
	UAshenPromiseLedgerComponent* PromiseLedger;

	UPROPERTY()
	UAshenSemanticContextMatcherComponent* ContextMatcher;

	UPROPERTY()
	UAshenRetroactiveMarginaliaInscriberComponent* MarginaliaInscriber;
};
