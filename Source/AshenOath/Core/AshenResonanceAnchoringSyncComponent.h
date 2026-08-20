// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenResonanceAnchoringSyncComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSyncComboExecutedSignature, FName, SyncComboID, float, TotalDamage);

/**
 * UAshenResonanceAnchoringSyncComponent
 *
 * Dual-character synchronized combo execution component (Kaelen + Garrett/Serafina sync moves).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenResonanceAnchoringSyncComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenResonanceAnchoringSyncComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonanceSync")
	bool ExecuteSyncCombo(FName SyncComboID, AActor* CompanionPartner, AActor* TargetActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonanceSync|Events")
	FOnSyncComboExecutedSignature OnSyncComboExecuted;
};
