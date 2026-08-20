// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenFederatedLoreResolverSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFederatedLoreResolvedSignature, FName, EntityID, FString, ResolvedLoreSummary, bool, bIsLoreAuthorityPRS);

/**
 * UAshenFederatedLoreResolverSubsystem
 *
 * Subsystem resolving lore questions via PRS graph authority and mechanics via C++ engine authority.
 */
UCLASS()
class ASHENOATH_API UAshenFederatedLoreResolverSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FederatedLore")
	FString ResolveFederatedLore(FName EntityID, bool bIsLoreQuery);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FederatedLore|Events")
	FOnFederatedLoreResolvedSignature OnLoreResolved;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|FederatedLore")
	int32 TotalLoreQueriesResolved = 0;
};
