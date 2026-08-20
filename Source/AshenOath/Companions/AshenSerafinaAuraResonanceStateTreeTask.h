// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaAuraResonanceStateTreeTask.generated.h"

/**
 * UAshenSerafinaAuraResonanceStateTreeTask
 * Custom StateTree task driving Serafina's protective aura pulsing.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAuraResonanceStateTreeTask : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAuraResonanceStateTreeTask();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float CalculateAuraPulseRadius(float SerafinaTrust) const;
};
