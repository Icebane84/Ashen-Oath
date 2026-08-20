// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenParryImpactCinematicSlowMoComponent.generated.h"

/**
 * UAshenParryImpactCinematicSlowMoComponent
 * Applies 0.2x time dilation on successful parry frame and restores speed after 0.25s.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParryImpactCinematicSlowMoComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenParryImpactCinematicSlowMoComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float DilationFactor = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float Duration = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void TriggerParrySlowMo();
};
