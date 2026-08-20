// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMiasmaVentActor.generated.h"

/**
 * AAshenMiasmaVentActor
 * Environmental geyser vent actor periodically erupting caustic void plumes in a 600uu radius.
 */
UCLASS()
class ASHENOATH_API AAshenMiasmaVentActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMiasmaVentActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float PlumeRadius = 600.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Hazard")
	bool bIsVentActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hazard")
	bool SealVent(AActor* InstigatingPlayer);
};
