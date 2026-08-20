// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenShadowOveruseAuditorComponent.generated.h"

/**
 * UAshenShadowOveruseAuditorComponent
 * 
 * Tracks frequency and total corruption cost of Ashen Mark abilities in combat,
 * triggering companion warnings or physical body-block interventions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowOveruseAuditorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShadowOveruseAuditorComponent();

	/** Audits corruption expenditure and returns companion response */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Shadow")
	EShadowMarkOveruseResponse AuditShadowUsage(float CorruptionCost);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Shadow")
	float GetCombatCorruptionTotal() const { return CombatCorruptionTotal; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Companions|Shadow")
	float CombatCorruptionTotal = 0.0f;
};
