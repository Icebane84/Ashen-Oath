// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAtmosphericSanctuaryWardActor.generated.h"

/**
 * AAshenAtmosphericSanctuaryWardActor
 * Ancient protective ward creating a purified 1200uu sanctuary dome suppressing environmental miasma and storm hazards.
 */
UCLASS()
class ASHENOATH_API AAshenAtmosphericSanctuaryWardActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenAtmosphericSanctuaryWardActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	float PurifiedZoneRadius = 1200.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weather")
	bool bIsWardActivated = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	bool ActivateWard(AActor* InstigatingPlayer);
};
