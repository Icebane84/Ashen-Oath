// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenEmberEchoRetrievalActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmberEchoRetrievalSignature, float, RecoveredEmbers, int32, RecoveredImprints);

/**
 * AAshenEmberEchoRetrievalActor
 *
 * World memorial actor spawned at location of player death.
 * Holds lost Embers and pending Imprints, allowing Kaelen to retrieve lost resources upon overlap.
 */
UCLASS()
class ASHENOATH_API AAshenEmberEchoRetrievalActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenEmberEchoRetrievalActor();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* RetrievalVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* EchoMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Echo")
	float StoredEmbers = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Echo")
	int32 StoredImprintCount = 0;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Echo")
	void RetrieveEcho(AActor* PlayerActor);

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Echo|Events")
	FOnEmberEchoRetrievalSignature OnEchoRetrieved;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
