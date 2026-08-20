// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenEmpathicResonanceAnchorActor.generated.h"

/**
 * AAshenEmpathicResonanceAnchorActor
 * 3D interactive world anchor locking enemy mobility in place during Nova synchronization.
 */
UCLASS()
class ASHENOATH_API AAshenEmpathicResonanceAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenEmpathicResonanceAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nova")
	float StasisRadius = 800.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nova")
	bool bIsStasisLocked = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool LockEnemiesInStasis(AActor* InstigatingPlayer);
};
