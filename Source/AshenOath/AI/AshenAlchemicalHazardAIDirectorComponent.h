// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalHazardAIDirectorComponent.generated.h"

/**
 * UAshenAlchemicalHazardAIDirectorComponent
 * AI Director managing enemy hazard navigation, tripwire avoidance routines, and spell-cast recovery after being tripped.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalHazardAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalHazardAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool ShouldEvadeHazardLocation(const FVector& EnemyLocation, const FVector& HazardLocation, float HazardRadius) const;
};
