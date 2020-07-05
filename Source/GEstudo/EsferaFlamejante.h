// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EsferaFlamejante.generated.h"

UCLASS()
class GESTUDO_API AEsferaFlamejante : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEsferaFlamejante();

private:
	//Declara��o de um ponteiro que receber� o endere�o de um UStaticMeshComponente
	UPROPERTY(EditAnywhere, Category = "Components") UStaticMeshComponent* EsferaVisivel;
	//Declara��o de um ponteiro que receber� o endere�o de um USPhereComponente, o class serve para declarar o que s�r� antes e sua utiliza��o (foward declaration )
	UPROPERTY(EditAnywhere, Category = "Components") class USphereComponent* EsferaDeColisao;
	//Declara��o de um ponteiro para um componente de sistema de Particula
	UPROPERTY(EditAnywhere, Category = "Components") class UParticleSystemComponent* ParticulaDeFogo;


protected:

	//EditAnywhere 
	// A Variav�l estipulada ou moficada no: Editor da Unreal e Editor da Blueprint, MAS n�o fica dispon�vel no Event Graph da BluePrint

	//EditDefaultOnly
	// Pode-se Definir um valor padr�o para a vari�vel apenas na janela da Blueprint ANTES da execu��o do jogo. ( n�o fica acess�vel dentro do editor da Unreal e nem no Event)

	//VisibleAnywhere
	// Vari�vel vis�vel na janela de Detalhes do editor e Na janela de detalhes da Blueprint mas n�o poder� ser editada.

	//VisibleDefaultsOnlye
	// Vari�vel vis�vel na janela de propriedades do editor e na janela de detalhes da Blueprint mas n�o poder� ser editada.

	//BluePrintReadWrite
	// Permite que a vari�vel seja lida ou modificada apenas de dentro do Event Graph da BluePrint(Get e Set) (N�o disponivel no editor da Unreal e nem no editor da Blueprint)

	//BluePrintReadWrite
	// Permite que a vari�vel seja lida ou modificada apenas de dentro do Event Graph da BluePrint(Get e Set) (N�o disponivel no editor da Unreal e nem no editor da Blueprint) 

	//BluePrintReadOnly
	// Permite que a vari�vel seja lida ( get ) apenas de dentro do Event Graph da BluePrint(Get e Set) (N�o disponivel no editor da Unreal e nem no editor da Blueprint) 

	//Category = ""
	// Permite voc� agrupar vari�veis em uma �nica se��o dentro do editor da Unreal eou dentro da Blueprint. Quando us�rio procurar editar esta vari�vel no editor ou na blueprint, aparece sobre o titulo "Nome"

	// Voc� pode juntar EditAnywhere, BlueprintReadWrite e EditAnywhere, BlueprintReadOnly

	UPROPERTY(EditAnywhere, Category = "Variaveis") bool VariavelEditAnywhere;
	UPROPERTY(VisibleAnywhere, Category = "Variaveis") float VariavelVisibleAnywhere;
	UPROPERTY(EditDefaultsOnly, Category = "Variaveis") float  VariavelEditDefaultsOnly;
	UPROPERTY(VisibleDefaultsOnly, Category = "Variaveis") float VariavelVisibleDefaultsOnly;
	UPROPERTY(BlueprintReadWrite, Category = "Variaveis") FVector VariavelBlueprintReadWrite = FVector(0.f,0.f,-180.f);
	UPROPERTY(BlueprintReadOnly, Category = "Variaveis") FString VariavelBlueprintReadOnly = "Texto Blueprint";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")  FString VariavelEditAnywhereBlueprintReadWrite = "Texto Editavel";
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variaveis")  FString VariavelEditAnywhereBlueprintReadOnly = "Outro Texto Blueprint";

	//Macro UFUNCTION define fun��es e pode receber par�metros

	UFUNCTION() void IniciouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION() void TerminouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);

	//foward declaration: precisamos de class para indicar que apesar da classe n�o est�r ainda presente, ela ser� posteriormente anexada ao projeto no .cpp fazendo um include.
	UPROPERTY(EditAnywhere, Category="Texto") class UTextRenderComponent* TextoDeExibicao;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
