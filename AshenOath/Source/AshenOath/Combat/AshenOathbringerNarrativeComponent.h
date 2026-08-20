// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerNarrativeComponent.generated.h"

/**
 * UAshenOathbringerNarrativeComponent
 * Weapons inscribed with narrative memories gain scaling passive attack and poise modifiers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerNarrativeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathbringerNarrativeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative Weapon")
	float BaseScalingPerRune = 0.05f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative Weapon")
	float CalculateDamageBonusMultiplier(int32 RuneCount) const;
};
