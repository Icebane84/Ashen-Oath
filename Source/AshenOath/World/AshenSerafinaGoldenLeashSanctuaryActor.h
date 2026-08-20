// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSerafinaGoldenLeashSanctuaryActor.generated.h"

/**
 * AAshenSerafinaGoldenLeashSanctuaryActor
 * 3D metaphysical tether sanctuary actor maintaining a golden tether between Serafina and Kaelen to prevent dissolution into an Ash Walker.
 */
UCLASS()
class ASHENOATH_API AAshenSerafinaGoldenLeashSanctuaryActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSerafinaGoldenLeashSanctuaryActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Containment")
	float TetherRadiusUnits = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Containment")
	void EstablishMetaphysicalTether(AActor* SerafinaActor, AActor* KaelenActor);
};
