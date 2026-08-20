// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenSerafinaSoulAnchorAIComponent.generated.h"

/**
 * UAshenSerafinaSoulAnchorAIComponent
 * Serafina's AI decision tree: casts Sun-Pulse if Kaelen targets allies, channels Sanctuary Anchor to dampen shadow-core, or enters Bulwark Lockout at B >= 0.70.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSoulAnchorAIComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaSoulAnchorAIComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	EContainmentState CurrentContainmentAction = EContainmentState::StandardCooperation;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void EvaluateSerafinaContainmentTree(bool bIsKaelenUnchained, bool bIsKaelenTargetingAllies, float EmpathicBurnout);
};
