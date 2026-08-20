// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaAscensionAuraComponent.generated.h"

/**
 * UAshenSerafinaAscensionAuraComponent
 * Companion component emitting Serafina's ascension aura granting invulnerability frames during holy purges.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAscensionAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAscensionAuraComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float AscensionAuraRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void DeployAscensionAura();
};
